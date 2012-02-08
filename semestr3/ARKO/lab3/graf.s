section .text
global putLine

%idefine	ypos	[ebp + 16]

%idefine	xstart	[ebp - 4]
%idefine	xstop	[ebp - 8]
%idefine	xlength	[ebp - 12]
%idefine	width	[ebp - 16]
%idefine	horzB	[ebp - 20]
%idefine	horzG	[ebp - 24]
%idefine	horzR	[ebp - 28]
%idefine	dltB	[ebp - 32]
%idefine	dltG	[ebp - 36]
%idefine	dltR	[ebp - 40]

putLine:
push ebp
mov	ebp, esp

mov	edx,	[ebp+8]
mov	[lfrgb], edx 
mov	edx,	[ebp+12]
mov	[rtrgb], edx
mov	edx, [ebp+20]	; pInfo
mov	[imageStruct], edx
mov	edx, [ebp+24]	; lfdlt
mov	[lfdlt], edx
mov	edx, [ebp+28]	; ;lfrgb
mov	[rtdlt], edx

; get xstart
mov	eax,	[lfrgb]
mov	edx,	[eax+12]
add	edx, 0x8000
sar	edx, 16
mov	xstart, edx

; get xstop
mov	eax,	[rtrgb]
mov	edx,	[eax+12]
add	edx, 0x8000
sar	edx, 16
mov	xstop, edx

; width of the line drawn (in bytes)
mov 	ecx, xstart 	;xstart
mov 	edx, xstop 	;xstop
sub	edx, ecx
cmp	edx, 0
jne	continue	; if xlength == 0, xlenngth = 1
inc	edx
continue:
mov	xlength, edx
inc	edx
imul	edx, 3
mov	width, edx

;; horizontal line parameters
mov	eax,	[lfrgb]
mov	edx,	[eax]
mov	horzR,edx
mov	edx,	[eax+4]
mov	horzG,edx
mov	edx,	[eax+8]
mov	horzB,edx

mov	esi,	0

dltloop:
mov	edx,	[rtrgb]
mov	eax,	[edx+8+esi*4]
mov	ecx,	[ebp-20+esi*4]
mov	ebx,	xlength
sub	eax,	ecx
cdq
idiv	ebx	
mov	[ebp-32+esi*4],	eax

dec	esi
cmp	esi, -3
jnb	dltloop

; get line width in bytes
mov	edx, [imageStruct]
mov	ecx, [edx]
imul	ecx, 3		; in bytes
add	ecx, 3
sar	ecx, 2
sal	ecx, 2		; line width in ecx

; get current offset
mov	edx, ypos
imul	ecx, edx	
mov	eax, xstart
imul	eax, 3
add	ecx, eax
sub	ecx, 3		; eksp
mov	edx, ecx	; offset in bytes

; prepare for loop
mov	ecx, 0
mov	eax, [imageStruct]
mov	ebx, [eax+8]	;load image
add	ebx, edx

; drawing loop
loop:

mov	esi,	0
mov	edx, 	ebx
add	edx, 	ecx

rgbloop:
; draw
mov	eax, 	[ebp-28+esi*4]
sar	eax, 16
mov	[edx+esi], eax
; increment
mov	eax, 	[ebp-28+esi*4]
add	eax,	[ebp-40+esi*4]
mov	[ebp-28+esi*4],eax

inc	esi
cmp	esi, 3
jb	rgbloop

add	ecx, 3

cmp	ecx, width
jb	loop


; incrementation
;lfrgb[0] += lfdlt[0]
mov	esi,	0
mov	eax,	[lfdlt]
mov	ecx,	[lfrgb]

lfrgbloop:
mov	edx,	[eax+esi*4]
mov	ebx, 	[ecx+esi*4] 
add	ebx,	edx
mov	dword 	[ecx+esi*4], ebx
inc	esi
cmp	esi,	4
jb	lfrgbloop


; rtrgb[i] += rtdlt[i]
mov	esi,	0
mov	eax,	[rtdlt]
mov	ecx,	[rtrgb]

rtrgbloop:
mov	edx,	[eax+esi*4]
mov	ebx,	[ecx+esi*4] 
add	ebx,	edx
mov	[ecx+esi*4], ebx
inc	esi
cmp	esi, 4
jb	rtrgbloop

; exit

mov 	eax, dltR 

mov 	ebp, esp
pop 	ebp
ret

section .data
imageStruct	dd 	0

lfrgb		dd	0
rtrgb		dd	0
lfdlt		dd	0
rtdlt		dd	0


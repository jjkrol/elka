section .text
global putLine


putLine:
push ebp
mov	ebp, esp




mov	edx,	[ebp+8]
mov	[lfrgb], edx 

mov	edx,	[ebp+12]
mov	[rtrgb], edx

mov	edx, [ebp+16]	;y
mov	[y], edx

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
mov	[xstart], edx

; get xstop
mov	eax,	[rtrgb]
mov	edx,	[eax+12]
add	edx, 0x8000
sar	edx, 16
mov	[xstop], edx

; width of the line drawn (in bytes)
mov 	ecx, [xstart] 	;xstart
mov 	edx, [xstop] 	;xstop
sub	edx, ecx
cmp	edx, 0
jne	continue	; if xlength == 0, xlenngth = 1
add	edx, 2		; 1!
continue:
mov	[xlength], edx
inc	edx
imul	edx, 3
;add	edx, 6			dac czy nie?
mov	[width], edx

;; horizontal line parameters
mov	eax,	[lfrgb]
mov	edx,	[eax]
mov	[horzR],edx
mov	edx,	[eax+4]
mov	[horzG],edx
mov	edx,	[eax+8]
mov	[horzB],edx


mov	edx,	[rtrgb]
mov	eax,	[edx]
mov	ecx,	[horzR]
mov	ebx,	[xlength]
sub	eax,	ecx
cdq
idiv	ebx	
mov	[dltR],	eax

mov	edx,	[rtrgb]
mov	eax,	[edx+4]
mov	ecx,	[horzG]
mov	ebx,	[xlength]
sub	eax,	ecx
cdq
idiv	ebx
mov	[dltG],	eax
;
mov	edx,	[rtrgb]
mov	eax,	[edx+8]
mov	ecx,	[horzB]
mov	ebx,	[xlength]
sub	eax,	ecx
cdq
idiv	ebx			; eax / ebx
mov	[dltB],	eax

; get line width in bytes
mov	edx, [imageStruct]
mov	ecx, [edx]
imul	ecx, 3		; in bytes
add	ecx, 3
sar	ecx, 2
sal	ecx, 2
mov	[lineWidth], ecx

; get current offset
mov 	edx, [lineWidth]
mov	ecx, [y]
imul	ecx, edx	
mov	eax, [xstart]
imul	eax, 3
add	ecx, eax
sub	ecx, 3
mov	[offset], ecx

; prepare for loop
mov	ecx, 0
mov	eax, [imageStruct]
mov	edx, [eax+8]	;load image
mov	eax, [offset]
add	edx, eax

;; drawing loop
loop:

; RED
; draw
mov	eax, 	[horzR]
sar	eax, 16
mov	[edx+ecx], eax
; increment
mov	eax, 	[horzR]
mov	ebx,	[dltR]
add	eax,	ebx
mov	[horzR],eax

; GREEN
; draw
mov	eax, 	[horzG]
sar	eax, 16
mov	[edx+ecx+1], eax
; incremenet
mov	eax, 	[horzG]
mov	ebx,	[dltG]
add	eax,	ebx
mov	[horzG],eax

; BLUE
; draw
mov	eax, 	[horzB]
sar	eax, 16
mov	[edx+ecx+2], eax
; increment
mov	eax, 	[horzB]
mov	ebx,	[dltB]
add	eax,	ebx
mov	[horzB],eax

add	ecx, 3
cmp	ecx, [width]
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

mov 	eax, [dltR] 

mov 	ebp, esp
pop 	ebp
ret

section .data
imageStruct	dd 	0
width		dd 	0
lineWidth 	dd 	0
xlength		dd	0

lfrgb		dd	0
rtrgb		dd	0
lfdlt		dd	0
rtdlt		dd	0

xstart		dd 	0
xstop		dd	0
y		dd	0

rgbStruct	dd	0
horzR		dd	0
horzG		dd	0
horzB		dd	0

dltStruct	dd	0
dltR		dd	0
dltG		dd	0
dltB		dd	0
offset		dd	0

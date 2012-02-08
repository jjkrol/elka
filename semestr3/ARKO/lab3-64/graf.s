section .text
global putLine
; putLine(lfrgb, rtrgb, y, pInfo, lfdlt, rtdlt, horzrgb, horzdlt)
%idefine	rtarg	[rbp + 24]
%idefine	xstart	[rbp - 8]
%idefine	xstop	[rbp - 16]
%idefine	xlength	[rbp - 24]
%idefine	width	[rbp - 32]
%idefine	horzB	[rbp - 40]
%idefine	horzG	[rbp - 48]
%idefine	horzR	[rbp - 56]
%idefine	dltB	[rbp - 64]
%idefine	dltG	[rbp - 72]
%idefine	dltR	[rbp - 80]
%idefine	ypos	[rbp - 88]
%idefine	lfrgb	[rbp - 96]
%idefine	rtrgb	[rbp - 104]
%idefine	lfdlt	[rbp - 112]
%idefine	rtdlt	[rbp - 120]
%idefine	imageStruct	[rbp - 128]



putLine:
push rbp
mov	rbp, rsp
push	rbx

mov	lfrgb,	rdi 	; lfrgb
mov	rtrgb,	rsi 	; rtrgb
mov	lfdlt, 	r8		; lfdtl
mov	rtdlt,	r9		; rtdlf
mov	imageStruct, rcx
mov	ypos,	rdx


; get xstop
mov	rax,	rtrgb
mov	edx,dword	[rax+12]
add	rdx, 0x8000
sar	rdx, 16
mov	xstop, rdx 		;???

; get xstart
mov	rax,	lfrgb
xor	rdx, 	rdx
mov	edx,dword	[rax+12]
add	rdx, 0x8000
sar	rdx, 16
mov	xstart, edx





; width of the line drawn (in bytes)
mov 	rcx, xstart 	;xstart
mov 	rdx, xstop 	;xstop
sub	rdx, rcx
cmp	rdx, 0
jne	continue	; if xlength == 0, xlenngth = 1
inc	rdx
continue:
mov	xlength, rdx
inc	rdx
imul	rdx, 3
mov	width, rdx


;; horizontal line parameters
mov	rax,	lfrgb
mov	rdx,	[rax]
mov	horzR,rdx
mov	rdx,	[rax+8]
mov	horzG,rdx
mov	rdx,	[rax+16]
mov	horzB,rdx

mov	qword xlength, 4

mov	rdx,	rtrgb
mov	rax,	[rdx+16]
mov	rcx,	horzB	
mov	rbx,	xlength
sub	rax,	rcx
cdq
idiv	rbx	
mov	dltB,	rax
dec	rsi

mov	rdx,	rtrgb
mov	rax,	[rdx]
mov	rcx,	horzR
mov	rbx,	xlength
sub	rax,	rcx
cdq
idiv	rbx	
mov	dltR,	rax
dec	rsi

mov	rdx,	rtrgb
mov	rax,	[rdx+8]
mov	rcx,	horzG
mov	rbx,	xlength
sub	rax,	rcx
mov	rcx,	rax
cdq
idiv	rbx	
mov	dltG,	rax

mov 	rax, xstart
pop	rbx
mov 	rsp,	rbp
pop 	rbp
ret



; get line width in bytes
mov	rdx, imageStruct
mov	rcx, [rdx]
imul	rcx, 3		; in bytes
add	rcx, 3
sar	rcx, 2
sal	rcx, 2		; line width in ecx


; get current offset
mov	rdx, ypos
imul	rcx, rdx	
mov	rax, xstart
imul	rax, 3
add	rcx, rax
sub	rcx, 3		; eksp
mov	rdx, rcx	; offset in bytes


; prepare for loop
mov	rcx, 0
mov	rax, imageStruct
mov	rbx, [rax+8]	;load image
add	rbx, rdx


; drawing loop
loop:

mov	rsi,	0
mov	rdx, 	rbx
add	rdx, 	rcx

rgbloop:
; draw
mov	rax, 	[rbp-56+rsi*8]
sar	rax, 16
mov	[rdx+rsi], rax
; increment
mov	rax, 	[rbp-56+rsi*8]
add	rax,	[rbp-80+rsi*8]
mov	[rbp-56+rsi*8],rax

inc	rsi
cmp	rsi, 3
jb	rgbloop

add	rcx, 3

cmp	rcx, width
jb	loop


; incrementation
;lfrgb[0] += lfdlt[0]
mov	esi,	0
mov	eax,	lfdlt
mov	ecx,	lfrgb

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
mov	eax,	rtdlt
mov	ecx,	rtrgb

rtrgbloop:
mov	edx,	[eax+esi*4]
mov	ebx,	[ecx+esi*4] 
add	ebx,	edx
mov	[ecx+esi*4], ebx
inc	esi
cmp	esi, 4
jb	rtrgbloop

; exit

mov 	rax, xstart
pop	rbx
mov 	rsp,	rbp
pop 	rbp
ret

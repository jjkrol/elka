section .text
global putLine
putLine:
push ebp
mov	ebp, esp

mov	edx,	[ebp+8]
mov	[xstart], edx 

mov	edx,	[ebp+12]
add	edx,	2
mov	[xstop], edx

mov	edx, [ebp+16]	;y
mov	[y], edx

mov	edx, [ebp+20]	; pInfo
mov	[imageStruct], edx

mov	edx, [ebp+24]	; rgb
mov	[rgbStruct], edx

mov	edx, [ebp+28]	; rgb
mov	[dltStruct], edx

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
mov	[offset], ecx

; red green blue
mov	edx, [rgbStruct]
mov	eax, [edx]
mov	dword [horzR], eax
mov	eax, [edx+4]
mov	dword [horzG], eax
mov	eax, [edx+8]
mov	dword [horzB], eax

; dlts: red  green blue
mov	edx, [dltStruct]
mov	eax, [edx]
mov	dword [dltR], eax
mov	eax, [edx+4]
mov	dword [dltG], eax
mov	eax, [edx+8]
mov	dword [dltB], eax

; width of the line drawn (in bytes)
mov 	ecx, [xstart] 	;xstart
mov 	edx, [xstop] 	;xstop
sub	edx, ecx
inc	edx
imul	edx, 3
mov	[width], edx

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

; exit

mov 	eax, dword [dltR] 

mov 	ebp, esp
pop 	ebp
ret

section .data
imageStruct	dd 	0
width		dd 	0
lineWidth 	dd 	0
fullstartx	dd	0
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

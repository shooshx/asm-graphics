.486                     ;tells masm we want 32bit code, but not too fancy
.model flat, stdcall
option casemap :none 

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc

.data
caption BYTE "hello",0
text BYTE "Hello World!",0

.code
main PROC
    push 0
    push offset caption    
    push offset text
    push 0
    call MessageBoxA

    push 0
    call ExitProcess

main ENDP

end main

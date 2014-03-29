.486
.model flat, stdcall
option casemap :none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc

.data

wndClsName BYTE "WndClass",0
wndTitle BYTE "Window Title",0

.code
myWndProc PROC, hWnd:HWND, message:UINT, wParam:WPARAM, lParam:LPARAM 

    invoke DefWindowProc, hWnd, message, wParam, lParam
    ret
myWndProc ENDP

main PROC
    LOCAL wndcls: WNDCLASSA
    LOCAL hWnd: HWND
    LOCAL msg: MSG

    invoke RtlZeroMemory, addr wndcls, SIZEOF wndcls
    mov eax, offset wndClsName
    mov wndcls.lpszClassName, eax
    mov eax, myWndProc
    mov wndcls.lpfnWndProc, eax
    invoke RegisterClassA, addr wndcls

    invoke CreateWindowExA, 0, addr wndClsName, addr wndTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 800, 0,0,0,0
    mov hWnd, eax

    invoke ShowWindow, hWnd, SW_SHOW

msgLoop:
    invoke GetMessage, addr msg, 0,0,0
    cmp eax, 0
    jz endLoop
    invoke TranslateMessage, addr msg
    invoke DispatchMessage, addr msg
    jmp msgLoop

endLoop:
    push 0              
    call ExitProcess   
    ret
main ENDP               

end main                
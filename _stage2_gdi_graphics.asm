.486
.model flat, stdcall
option casemap :none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\gdi32.inc

.data

wndClsName BYTE "WndClass",0
wndTitle BYTE "Window Title",0
text BYTE "Hello, Windows!",0
squareX DWORD 100

.code

drawRect PROC, hdc: HDC, x1:DWORD, y1:DWORD, x2:DWORD, y2:DWORD
    LOCAL rect: RECT
    LOCAL brush: HBRUSH 

    mov eax, x1
    mov rect.left, eax
    mov eax, y1
    mov rect.top, eax
    mov eax, x2
    mov rect.right, eax
    mov eax, y2
    mov rect.bottom, eax
    invoke CreateSolidBrush, 0ff0000h
    mov brush, eax
    invoke FillRect, hdc, addr rect, brush
    invoke DeleteObject, brush
    
    ret
drawRect ENDP




myWndProc PROC, hWnd:HWND, message:UINT, wParam:WPARAM, lParam:LPARAM 
    LOCAL hdc: HDC
    LOCAL ps: PAINTSTRUCT 

    cmp message, WM_PAINT
    jne nextMsg1
        invoke BeginPaint, hWnd, addr ps
        mov hdc, eax
        invoke TextOutA, hdc, 0, 0, addr text, 15; 

        mov eax, squareX
        add eax, 100
        invoke drawRect, hdc, squareX, 100, eax, 200
        invoke EndPaint, hWnd, addr ps
nextMsg1:
    cmp message, WM_KEYDOWN
    jne nextMsg2
        cmp wParam, VK_LEFT
        jne nextVk1
        sub squareX, 5
        jmp keyEnd
nextVk1:
        cmp wParam, VK_RIGHT
        jne nextVk2
        add squareX, 5
        jmp keyEnd
nextVk2:
keyEnd:
        invoke InvalidateRect, hWnd, NULL, TRUE
nextMsg2:
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
    invoke GetStockObject, WHITE_BRUSH
    mov wndcls.hbrBackground, eax
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
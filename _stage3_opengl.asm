.486                     ;tells masm we want 32bit code, but not too fancy
.model flat, stdcall
option casemap :none 

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc

include OpenGL\gl.inc
include OpenGL\glut.inc

includelib opengl32.lib
includelib glut-3.7.6-bin\glut32.lib

.data
text BYTE "Hello World!",0
appname BYTE "hello",0

f0_5 REAL4 0.5f
f1_0 REAL4 1.0f

.code

displayFunc PROC
    invoke glClearColor, 0,0,0,0;
    invoke glClear, GL_COLOR_BUFFER_BIT

    invoke glBegin, GL_TRIANGLES
        invoke glColor3f, f1_0,0,0
        invoke glVertex2f, 0,0

        invoke glColor3f, 0,f1_0,0
        invoke glVertex2f, f0_5,0

        invoke glColor3f, 0,0,f1_0
        invoke glVertex2f, f0_5,f0_5
    invoke glEnd
    invoke glutSwapBuffers
    ret
displayFunc ENDP

main PROC
    invoke glutInitDisplayMode, GLUT_DEPTH or GLUT_DOUBLE or GLUT_RGBA  

    invoke glutInitWindowSize, 800,800
    invoke glutCreateWindow, addr text
    invoke glutDisplayFunc, displayFunc
  
    invoke glutMainLoop

    push 0
    call ExitProcess
    ret
main ENDP

end main

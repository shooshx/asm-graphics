
#include <Windows.h>

#include "glut-3.7.6-bin/glut.h"



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_KEYDOWN:
        if(wParam == VK_ESCAPE) {
            PostQuitMessage(0);
            return 0;
        }
        break;
    } // switch

    return DefWindowProc(hWnd, message, wParam, lParam);
} 

void display(void)
{
  glClearColor(1,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  {
    glColor3f(1,0,0);
    glVertex2f(0,0);

    glColor3f(0,1,0);
    glVertex2f(.5,0);

    glColor3f(0,0,1);
    glVertex2f(.5,.5);
  }
  glEnd();

  glutSwapBuffers();
}



int xmain(int argc, char* argv[])
{
    //glutInit(&argc, argv);
  
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  
    //glutInitWindowPosition(200,200);
    glutInitWindowSize(800,800);
    glutCreateWindow("Part 1");
    glutDisplayFunc(display);
   // glutReshapeFunc(reshape);
  
    glutMainLoop();



    return 0;

    HWND hWnd;
    WNDCLASSA wc;

    wc.style = 0;//CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = NULL;// hInst;
    wc.hIcon = NULL;//LoadIcon(hInst, IDI_APPLICATION);
    wc.hCursor = NULL;//LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;//(HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszMenuName = NULL;//L"";
    wc.lpszClassName = "WndClass";
    RegisterClassA(&wc);


    hWnd = CreateWindowExA(
        0,
        "WndClass", "WndName",
        WS_OVERLAPPEDWINDOW, //style
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
        NULL, NULL, NULL, NULL);

    ShowWindow(hWnd, SW_SHOW);
    //UpdateWindow(hWnd);
    //SetFocus(hWnd);

    MSG msg;
    while ( GetMessage( &msg, NULL, 0, 0 ) != 0)
    { 
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    } 


    return 0;
}


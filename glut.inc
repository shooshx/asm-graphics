; GLUT include file for MASM
; /Mic, 2003
;
; Not all constants/functions are included in this version.
;


GLUT_API_VERSION	equ 3

GLUT_RGB		equ 0
GLUT_RGBA		equ GLUT_RGB
GLUT_INDEX		equ 1
GLUT_SINGLE		equ 0
GLUT_DOUBLE		equ 2
GLUT_ACCUM		equ 4
GLUT_ALPHA		equ 8
GLUT_DEPTH		equ 16
GLUT_STENCIL		equ 32

; Mouse buttons. 
GLUT_LEFT_BUTTON	equ 0
GLUT_MIDDLE_BUTTON	equ 1
GLUT_RIGHT_BUTTON	equ 2

; Mouse button  state. 
GLUT_DOWN		equ 0
GLUT_UP			equ 1

; Function keys 
GLUT_KEY_F1		equ 1
GLUT_KEY_F2		equ 2
GLUT_KEY_F3		equ 3
GLUT_KEY_F4		equ 4
GLUT_KEY_F5		equ 5
GLUT_KEY_F6		equ 6
GLUT_KEY_F7		equ 7
GLUT_KEY_F8		equ 8
GLUT_KEY_F9		equ 9
GLUT_KEY_F10		equ 10
GLUT_KEY_F11		equ 11
GLUT_KEY_F12		equ 12
; Directional keys 
GLUT_KEY_LEFT		equ 100
GLUT_KEY_UP		equ 101
GLUT_KEY_RIGHT		equ 102
GLUT_KEY_DOWN		equ 103
GLUT_KEY_PAGE_UP	equ 104
GLUT_KEY_PAGE_DOWN	equ 105
GLUT_KEY_HOME		equ 106
GLUT_KEY_END		equ 107
GLUT_KEY_INSERT		equ 108

; Entry/exit  state. 
GLUT_LEFT		equ 0
GLUT_ENTERED		equ 1

; Menu usage  state. 
GLUT_MENU_NOT_IN_USE	equ 0
GLUT_MENU_IN_USE	equ 1

; Visibility  state. 
GLUT_NOT_VISIBLE	equ 0
GLUT_VISIBLE		equ 1

; Window status  state. 
GLUT_HIDDEN		equ 0
GLUT_FULLY_RETAINED	equ 1
GLUT_PARTIALLY_RETAINED	equ 2
GLUT_FULLY_COVERED	equ 3

; Color index component selection values. 
GLUT_RED		equ 0
GLUT_GREEN		equ 1
GLUT_BLUE		equ 2

; Layers for use. 
GLUT_NORMAL		equ 0
GLUT_OVERLAY		equ 1

; glutGet parameters. 
GLUT_WINDOW_X		equ 100
GLUT_WINDOW_Y		equ 101
GLUT_WINDOW_WIDTH	equ 102
GLUT_WINDOW_HEIGHT	equ 103
GLUT_WINDOW_BUFFER_SIZE	equ 104
GLUT_WINDOW_STENCIL_SIZE equ 105
GLUT_WINDOW_DEPTH_SIZE	equ 106
GLUT_WINDOW_RED_SIZE	equ 107
GLUT_WINDOW_GREEN_SIZE	equ 108
GLUT_WINDOW_BLUE_SIZE	equ 109
GLUT_WINDOW_ALPHA_SIZE	equ 110
GLUT_WINDOW_ACCUM_RED_SIZE equ 111
GLUT_WINDOW_ACCUM_GREEN_SIZE equ 112
GLUT_WINDOW_ACCUM_BLUE_SIZE equ 113
GLUT_WINDOW_ACCUM_ALPHA_SIZE equ 114
GLUT_WINDOW_DOUBLEBUFFER equ 115
GLUT_WINDOW_RGBA	equ 116
GLUT_WINDOW_PARENT	equ 117
GLUT_WINDOW_NUM_CHILDREN equ 118
GLUT_WINDOW_COLORMAP_SIZE equ 119
GLUT_WINDOW_NUM_SAMPLES	equ 120
GLUT_WINDOW_STEREO	equ 121
GLUT_WINDOW_CURSOR	equ 122
GLUT_SCREEN_WIDTH	equ 200
GLUT_SCREEN_HEIGHT	equ 201
GLUT_SCREEN_WIDTH_MM	equ 202
GLUT_SCREEN_HEIGHT_MM	equ 203
GLUT_MENU_NUM_ITEMS	equ 300
GLUT_DISPLAY_MODE_POSSIBLE equ 400
GLUT_INIT_WINDOW_X	equ 500
GLUT_INIT_WINDOW_Y	equ 501
GLUT_INIT_WINDOW_WIDTH	equ 502
GLUT_INIT_WINDOW_HEIGHT	equ 503
GLUT_INIT_DISPLAY_MODE	equ 504
GLUT_ELAPSED_TIME	equ 700

; glutDeviceGet parameters.
GLUT_HAS_KEYBOARD	equ 600
GLUT_HAS_MOUSE		equ 601
GLUT_HAS_SPACEBALL	equ 602
GLUT_HAS_DIAL_AND_BUTTON_BOX equ 603
GLUT_HAS_TABLET		equ 604
GLUT_NUM_MOUSE_BUTTONS	equ 605
GLUT_NUM_SPACEBALL_BUTTONS equ 606
GLUT_NUM_BUTTON_BOX_BUTTONS equ 607
GLUT_NUM_DIALS		equ 608
GLUT_NUM_TABLET_BUTTONS	equ 609

; glutLayerGet parameters. 
GLUT_OVERLAY_POSSIBLE   equ 800
GLUT_LAYER_IN_USE	equ 801
GLUT_HAS_OVERLAY	equ 802
GLUT_TRANSPARENT_INDEX	equ 803
GLUT_NORMAL_DAMAGED	equ 804
GLUT_OVERLAY_DAMAGED	equ 805

; glutUseLayer parameters. 
GLUT_NORMAL		equ 0
GLUT_OVERLAY		equ 1

; glutGetModifiers return mask. 
GLUT_ACTIVE_SHIFT       equ 1
GLUT_ACTIVE_CTRL        equ 2
GLUT_ACTIVE_ALT         equ 4

; glutSetCursor parameters. 
; Basic arrows. 
GLUT_CURSOR_RIGHT_ARROW	equ 0
GLUT_CURSOR_LEFT_ARROW	equ 1
; Symbolic cursor shapes. 
GLUT_CURSOR_INFO	equ 2
GLUT_CURSOR_DESTROY	equ 3
GLUT_CURSOR_HELP	equ 4
GLUT_CURSOR_CYCLE	equ 5
GLUT_CURSOR_SPRAY	equ 6
GLUT_CURSOR_WAIT	equ 7
GLUT_CURSOR_TEXT	equ 8
GLUT_CURSOR_CROSSHAIR	equ 9
; Directional cursors. 
GLUT_CURSOR_UP_DOWN	equ 10
GLUT_CURSOR_LEFT_RIGHT	equ 11
; Sizing cursors. 
GLUT_CURSOR_TOP_SIDE	equ 12
GLUT_CURSOR_BOTTOM_SIDE	equ 13
GLUT_CURSOR_LEFT_SIDE	equ 14
GLUT_CURSOR_RIGHT_SIDE	equ 15
GLUT_CURSOR_TOP_LEFT_CORNER equ 16
GLUT_CURSOR_TOP_RIGHT_CORNER equ 17
GLUT_CURSOR_BOTTOM_RIGHT_CORNER	equ 18
GLUT_CURSOR_BOTTOM_LEFT_CORNER	equ 19
; Inherit from parent window. 
GLUT_CURSOR_INHERIT	equ 100
; Blank cursor. 
GLUT_CURSOR_NONE	equ 101
; Fullscreen crosshair (if available). 
GLUT_CURSOR_FULL_CROSSHAIR equ 102




glut_dpush MACRO numb
	LOCAL prmstr,prmlen,x
 	prmstr EQU <numb>
 	prmlen SIZESTR prmstr
 	x SUBSTR prmstr,prmlen,1
 	IFIDNI x,<f>
 		x SUBSTR prmstr,1,prmlen-1
 		real8 &x
 		db 68h
 		real8 &x
 		ORG $-8-1-8
 		db 8Dh,40h,0 ; lea eax,[eax+0]
 		db 68h
 		ORG $+4+1+4
 	ELSE
 		x CATSTR prmstr,<[4]>
 		mov eax,eax
 		mov ebx,ebx
 		push dword ptr x
 		push dword ptr prmstr
 	ENDIF
ENDM


glutCreateWindow PROTO :DWORD
glutCreateSubWindow PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

glutDestroyWindow PROTO :DWORD
glutDeviceGet PROTO :DWORD
glutDisplayFunc PROTO :DWORD

glutEntryFunc PROTO :DWORD 
glutFullScreen PROTO

glutGet PROTO :DWORD
glutGetWindow PROTO

glutHideWindow PROTO

glutIconifyWindow PROTO
glutIdleFunc PROTO :DWORD
glutInit PROTO :DWORD,:DWORD
glutInitDisplayMode PROTO :DWORD
glutInitWindowSize PROTO :DWORD,:DWORD

glutKeyboardFunc PROTO :DWORD

glutMainLoop PROTO 
glutMenuStateFunc PROTO :DWORD
glutMotionFunc PROTO :DWORD 
glutMouseFunc PROTO :DWORD

glutPassiveMotionFunc PROTO :DWORD 
glutPopWindow PROTO
glutPositionWindow PROTO :DWORD,:DWORD
glutPostRedisplay PROTO
glutPushWindow PROTO

glutReshapeFunc PROTO :DWORD
glutReshapeWindow PROTO :DWORD,:DWORD

glutSetCursor PROTO :DWORD
glutSetIconTitle PROTO :DWORD
glutSetWindow PROTO :DWORD
glutSetWindowTitle PROTO :DWORD
glutShowWindow PROTO
glutSolidCone PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glutSolidCube PROTO :DWORD,:DWORD
glutSolidSphere PROTO :DWORD,:DWORD,:DWORD,:DWORD
glutSwapBuffers PROTO 

glutTimerFunc PROTO :DWORD,:DWORD,:DWORD

glutVisibilityFunc PROTO :DWORD 

glutWireCone PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
glutWireCube PROTO :DWORD,:DWORD
glutWireSphere PROTO :DWORD,:DWORD,:DWORD,:DWORD


_glutWireSphere MACRO radius,slices,stacks
	push stacks
	push slices
	glut_dpush radius
	call glutWireSphere
ENDM


_glutSolidSphere MACRO radius,slices,stacks
	push stacks
	push slices
	glut_dpush radius
	call glutSolidSphere
ENDM


_glutWireCone MACRO base,height,slices,stacks
	push stacks
	push slices
	glut_dpush height
	glut_dpush base
	call glutWireCone
ENDM


_glutSolidCone MACRO base,height,slices,stacks
	push stacks
	push slices
	glut_dpush height
	glut_dpush base
	call glutSolidCone
ENDM





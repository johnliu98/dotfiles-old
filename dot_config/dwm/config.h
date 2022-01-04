/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx      = 0;        /* border pixel of windows */
static const unsigned int snap          = 0;        /* snap pixel */
static const unsigned int cornerrad     = 25;       /* corner radius */
static const unsigned int gappih        = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv        = 10;       /* vert inner gap between windows */
static const unsigned int gappoh        = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov        = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps              = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar                = 1;        /* 0 means no bar */
static const int topbar                 = 1;        /* 0 means bottom bar */
static char      *fonts[]               = { "UbuntuMono Nerd Font:size=20" };
static const char dmenufont[]           = "UbuntuMono Nerd Font:size=20";
static const char col_gray1[]           = "#222222";
static const char col_gray2[]           = "#444444";
static const char col_gray3[]           = "#bbbbbb";
static const char col_gray4[]           = "#eeeeee";
static const char col_cyan[]            = "#005577";
static const char col_white[]           = "#bbbbbb" ;
static const unsigned int baralpha      = 0xaa;
static const unsigned int borderalpha   = OPAQUE;
static const float mfact                = 0.5;      /* factor of master area size [0.05..0.95] */
static const int nmaster                = 1;        /* number of clients in master area */
static const int resizehints            = 0;        /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen         = 1;        /* 1 will force focus on the fullscreen window */

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_white  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm",  "-g", "120x34",                        NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spfm",    "-g", "144x41", "-e", "ranger",        NULL };
const char *spcmd3[] = {TERMINAL, "-n", "spcalc",  "-g", "50x20",  "-e", "bc",     "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"spcalc",      spcmd3},
};

/* tagging */
static const char *tags[] = { "", "", "", "嗢", "ﴣ", "ﯧ", "ﰕ", "望", "" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance        title               tags mask     isfloating    isterminal   monitor */
	{ NULL,                 NULL,			"Google Chrome",	1 << 1,			0,              0,			 -1 },
	{ TERMCLASS,		    NULL,	        NULL,		        0,		        0,              1,			 -1 },
	{ "Slack",              NULL,			NULL,		        1 << 8,			0,              0,			 -1 },
	{ "Zulip",              NULL,			NULL,		        1 << 8,			0,              0,			 -1 },
	{ NULL,		            "vlc",		    NULL,		        1 << 3,		    0,              0,			 -1 },
	{ NULL,		            "spterm",		NULL,		        SPTAG(0),		1,              1,			 -1 },
	{ NULL,		            "spfm",		    NULL,		        SPTAG(1),		1,              1,			 -1 },
	{ NULL,		            "spcalc",	    NULL,		        SPTAG(2),		1,              0,			 -1 },
	{ "Evince",		        NULL,	        NULL,		        1 << 2,		    0,              0,			 -1 },
};

/* layout(s) */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "H[]",      deck },
	{ "###",      nrowgrid },
	{ "TTT",      bstack },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

static const Taglayout taglayouts[] = {
	/* tag		layout */
	{ 3,		{.v = &layouts[1]} },
	{ 9,		{.v = &layouts[1]} },
};

/* key definitions */
#define MODKEY    Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },
	/* { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \ */
	/* { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"
#include "movestack.c"

/* Hex strings for Swedish characters
*   character       hex
*   å               0xe5
*   ä               0xe4
*   ö               0xf6
*/
static Key keys[] = {
	/* modifier                     key                 function        argument */
  /* General key settings */
	{ MODKEY,                       XK_d,               spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,          spawn,          {.v = termcmd } },
	{ MODKEY,			            XK_w,	            spawn,	        SHCMD("google-chrome-stable") },
	{ MODKEY,                       XK_b,               togglebar,      {0} },
    { MODKEY|ShiftMask,             XK_r,               quit,           {1} },

  /* Dmenu scripts */
	{ MODKEY,                       XK_p,               spawn,          SHCMD("passmenu -i -l 10") },
	{ MODKEY,			            0xe4,               spawn,          SHCMD("dm-emoji") },
	{ MODKEY,			            XK_m,               spawn,          SHCMD("dm-netflix") },
	{ MODKEY,			            0xf6,               spawn,          SHCMD("dm-zotero-pdf") },
	{ MODKEY,			            XK_c,               spawn,          SHCMD("dm-configs") },
	{ MODKEY|ShiftMask,             XK_q,               spawn,          SHCMD("dm-power-button") },

  /* Screenshot */
	{ MODKEY,                       XK_Print,           spawn,          SHCMD("import -window root $HOME/Pictures/screenshots/$(date '+%Y-%m-%d_%H-%M-%S.png')") },
	{ 0,                            XK_Print,           spawn,          SHCMD("import $HOME/Pictures/screenshots/$(date '+%Y-%m-%d_%H-%M-%S.png')") },

  /* Navigation */
	{ MODKEY,                       XK_j,               focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,               focusstack,     {.i = -1 } },
    { MODKEY,                       XK_l,               shiftview,      {.i = +1 } },
    { MODKEY,                       XK_h,               shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_0,               view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,               tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Tab,             view,           {0} },
	{ MODKEY,                       XK_comma,           focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,          focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,           tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,          tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

  /* Window manipulation */
	{ MODKEY,                       XK_space,           zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,           togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_h,               setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,               setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,               movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,               movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,               incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,               incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_f,               togglefullscr,  {0} },
	{ MODKEY,                       XK_q,               killclient,     {0} },

	{ MODKEY|ShiftMask,  			XK_Return,          togglescratch,  {.ui = 0 } },
	{ MODKEY,            			XK_r,	            togglescratch,  {.ui = 1 } },
	{ MODKEY|ShiftMask,             XK_c,	            togglescratch,  {.ui = 2 } },

	{ MODKEY,                       XK_t,               setlayout,      {.v = &layouts[0]} },
	// { MODKEY|ShiftMask,             XK_t,               setlayout,      {.v = &layouts[1]} },
	// { MODKEY,                       XK_y,               setlayout,      {.v = &layouts[2]} },
	// { MODKEY|ShiftMask,             XK_y,               setlayout,      {.v = &layouts[3]} },
	{ MODKEY,		                XK_o,               cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,               cyclelayout,    {.i = -1 } },

  /* Brightness */
	{ 0, XF86XK_MonBrightnessUp,	                    spawn,		    SHCMD("xbacklight -inc 10") },
	{ 0, XF86XK_MonBrightnessDown,                      spawn,		    SHCMD("xbacklight -dec 10") },
	{ MODKEY|ShiftMask,             XK_plus,	        spawn,		    SHCMD("xbacklight -set 100") },
	{ MODKEY|ShiftMask,             XK_minus,	        spawn,		    SHCMD("xbacklight -set 1") },

  /* Audio */
	{ 0, XF86XK_AudioMute,		                        spawn,		    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioRaiseVolume,	                    spawn,		    SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioLowerVolume,	                    spawn,		    SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask          button          function        argument */
	{ ClkLtSymbol,          0,                  Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                  Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                  Button2,        zoom,           {0} },
	/* { ClkStatusText,        0,                  Button3,        spawn,          {.v = termcmd } }, */
	{ ClkStatusText,        0,                  Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,                  Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,                  Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,                  Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,                  Button5,        sigstatusbar,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,          Button1,        sigstatusbar,   {.i = 6} },
	{ ClkClientWin,         MODKEY,             Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,             Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,                  Button1,        view,           {0} },
	{ ClkTagBar,            0,                  Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,             Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,             Button3,        toggletag,      {0} },
};

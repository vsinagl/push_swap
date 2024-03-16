let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Code/42/push_swap
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +123 project/main.c
badd +67 project/sort.c
badd +53 project/utils2.c
badd +101 project/utils1.c
badd +13 pushswap.h
badd +15 project/ops1.c
badd +2 ~/Code/42/push_swap/.gitignore
badd +25 ~/Code/42/push_swap/project/list.c
badd +0 sort_test
badd +11 injection2_test.sh
argglobal
%argdel
$argadd project/main.c
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit injection2_test.sh
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 93 + 81) / 162)
exe 'vert 2resize ' . ((&columns * 67 + 81) / 162)
exe 'vert 3resize ' . ((&columns * 0 + 81) / 162)
argglobal
balt project/utils1.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 11 - ((10 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 021|
wincmd w
argglobal
if bufexists(fnamemodify("project/sort.c", ":p")) | buffer project/sort.c | else | edit project/sort.c | endif
if &buftype ==# 'terminal'
  silent file project/sort.c
endif
balt project/utils1.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 53 - ((13 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 53
normal! 012|
wincmd w
argglobal
if bufexists(fnamemodify("project/utils1.c", ":p")) | buffer project/utils1.c | else | edit project/utils1.c | endif
if &buftype ==# 'terminal'
  silent file project/utils1.c
endif
balt project/utils2.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 57 - ((31 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 57
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 93 + 81) / 162)
exe 'vert 2resize ' . ((&columns * 67 + 81) / 162)
exe 'vert 3resize ' . ((&columns * 0 + 81) / 162)
tabnext
edit project/sort.c
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 104 - ((37 * winheight(0) + 31) / 63)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 104
normal! 0
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :

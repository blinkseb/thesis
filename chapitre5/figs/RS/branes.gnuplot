unset key
unset border
unset ytics
unset xtics

set samples 1000

set xrange [0:10]
set yrange [0:10]

#set terminal svg size 800,600 dynamic enhanced
set terminal pdfcairo enhanced color size 20cm,10cm font "TeX Gyre Pagella,18"
#set output "RS_wave_functions.svg"
set output "RS_wave_functions.pdf"

#set arrow from 0,0 to 10,0
set arrow 1 from -0.3,0 to 10.3,0 head front filled linetype 1 linecolor rgb "black" linewidth 4 size screen 0.025,30.000,45.000

set arrow 2 from 0,-1 to 0,12 nohead back linetype 1 linecolor rgb "black" linewidth 4
set arrow 3 from 10,-1 to 10,12 nohead back linetype 1 linecolor rgb "black" linewidth 4

#plot [x=0:10] 10*exp(-10*x)

set label "t_R" at 9.4,9
set label "gluons K.K." at 7.35,2
set label "H" at 9.6,3
set label "(u, d)_L" at 0.4,7.5

set label "{/=14 y}" at 4.6,-0.25

set label "{/=14 0}" at 0.05,-0.28
set label "{/=14 ±πR}" at 9.6,-0.28

set label "TeV brane" at 10.2,5 rotate by -90 center
set label "Planck brane" at -0.2,5 rotate by 90 center

set label "Bulk" at 4.5,10

plot 10*exp(-1*x) lw 6 lt rgb "#f38630", 10*exp(0.5*(x - 10)) lw 6 lt rgb "#c44d58", 10*exp(15*(x - 10)) lw 6 lt rgb "#0b486b", 10*exp(1.3*(x - 10)) lt 0 lw 10 lc rgb "#00A0B0"

set title "Graphs"
set xlabel "X-axis"
set ylabel "Y1 and Y2"
set xr[0:20]
set yr[0:200]

fit_y1(x) = a1*x*x + b1*x + c1
fit_y2(x) = a2*x*x + b2*x + c2

fit fit_y1(x) "code1.dat" using 1:2 via a1,b1,c1

set label 1 sprintf("a1 = %.3f, b1 = %.3f, c1 = %.3f", a1, b1, c1) at 1,190

plot "code1.dat" using 1:2 title "y1" with lp, \
        "code1.dat" using 1:3 title "y2" with lp, \
        fit_y1(x)


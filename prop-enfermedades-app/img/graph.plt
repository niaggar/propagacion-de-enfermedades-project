set terminal pngcairo enhanced color size 1200,600
set output "./result/comportamiento.png"

# set xrange[0 : 5.61985]
# set yrange[-6:7]

set key top left
set title "Velocidad y posicion de la particula"
set xlabel "Tiempo [Dias]"
set ylabel "Razon de poblacion"

plot "../data/data.dat" i 0 u 1:2 w l lw 4 lc "#5c6d70" t "suceptibles", "../data/data.dat" i 0 u 1:3 w l lw 4 lc "#a37774" t "infectados", "../data/data.dat" i 0 u 1:4 w l lw 4 lc "#e88873" t "recuperados",

unset output
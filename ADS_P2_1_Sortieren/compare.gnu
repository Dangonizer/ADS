reset
set xrange[1:250]
set autoscale y
set xlabel "n [-]"
set ylabel "t [ns]"
set key top left

plot \
"quicksort_comp.txt" with linespoints title 'Quicksort',\
"insertionsort.txt" with linespoints title 'Mergesort',\

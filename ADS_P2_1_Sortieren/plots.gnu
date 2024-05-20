reset
set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [ns]"
set key top left

plot \
"quicksort.txt" with linespoints title 'Quicksort',\
"mergesort.txt" with linespoints title 'Mergesort',\
"shellsort_2n.txt" with linespoints title 'Shellsort',\
"heapsort.txt" with linespoints title 'Heapsort',\
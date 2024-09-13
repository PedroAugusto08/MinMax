set terminal pngcairo   # Define o formato de saída do gráfico (neste caso, PNG)
set output 'grafico.png'   # Define o nome do arquivo de saída

set title "Gráfico MINMAX 1"   # Título do gráfico
set xlabel "Tempo (e-03s)"       # Rótulo do eixo X
set ylabel "Tamanho do Vetor (n)"       # Rótulo do eixo Y
set logscale xy 
set xrange [0.005:100]
set yrange [1000:5000000]
set key top left

# Define cores RGB personalizadas
set linetype 1 lc rgb "#E41A1C" lw 2 pt 7
set linetype 2 lc rgb "#377EB8" lw 2 pt 5
set linetype 3 lc rgb "#4DAF4A" lw 2 pt 9

# Define o estilo do plot e plota todos os conjuntos de dados em um único comando plot
plot for [i=0:3] 'dados1.txt' every ::i*4::i*4+3 with linespoints lt i+1 title sprintf("MINMAX [RANDOM] %d", i+1), \
     for [i=0:3] 'dados2.txt' every ::i*4::i*4+3 with linespoints lt i+4 title sprintf("MINMAX [CRESC] %d", i+1), \
     for [i=0:3] 'dados3.txt' every ::i*4::i*4+3 with linespoints lt i+7 title sprintf("MINMAX [DECRESC] %d", i+1)

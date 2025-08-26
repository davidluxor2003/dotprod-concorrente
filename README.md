1) Teste com vetor de N = 100.000

./seq 100000 entrada.bin
./conc 1 entrada.bin
./conc 2 entrada.bin
./conc 4 entrada.bin

1 Thread-
Produto interno (sequencial) = 25093.603564
Produto interno (concorrente) = 25093.603564
Erro relativo = 0.000000e+00
Tempo concorrente = 0.000791 segundos

2 Threads-
Produto interno (sequencial) = 25093.603564
Produto interno (concorrente) = 25093.603564
Erro relativo = 2.899527e-16
Tempo concorrente = 0.000705 segundos

4 Threads-
Produto interno (sequencial) = 25093.603564
Produto interno (concorrente) = 25093.603564
Erro relativo = 4.349290e-16
Tempo concorrente = 0.000652 segundos

2) Teste com vetor de N = 10.000.000
./seq 10000000 entrada.bin
./conc 1 entrada.bin
./conc 2 entrada.bin
./conc 4 entrada.bin

Produto interno (sequencial) = 2500307.211798
Produto interno (concorrente) = 2500307.211798
Erro relativo = 0.000000e+00
Tempo concorrente = 0.039223 segundos

Produto interno (sequencial) = 2500307.211798
Produto interno (concorrente) = 2500307.211798
Erro relativo = 9.498323e-15
Tempo concorrente = 0.024627 segundos

Produto interno (sequencial) = 2500307.211798
Produto interno (concorrente) = 2500307.211798
Erro relativo = 3.352349e-15
Tempo concorrente = 0.011466 segundos

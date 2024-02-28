public class SelectSort {


    public static void selectSort(int[] numeros) {
        int tamaho = numeros.length;
        int trocas = 0;
        int comparacoes = 0;

        int i, j, numeroSelecionado, menorNumero, posicaoMenorNumero;

        for (i = 0; i < tamaho - 1; i++) {
            numeroSelecionado = numeros[i];
            menorNumero = numeros[i + 1];
            posicaoMenorNumero = i + 1;
            
            for (j = i + 1; j < tamaho; j++) {
                comparacoes++;
                if (numeros[j] < menorNumero) {
                    menorNumero = numeros[j];
                    posicaoMenorNumero = j;
                }
            }
            
            if (menorNumero < numeroSelecionado) {
                numeros[i] = numeros[posicaoMenorNumero];
                numeros[posicaoMenorNumero] = numeroSelecionado;
                trocas++;
            }
        }
        System.out.println("Trocas: " + trocas);
        System.out.println("Comparações: " + comparacoes);
    }

    public static void main(String[] args) {
        long tempoInicial = System.currentTimeMillis();
        LerArquivo lerArquivo = new LerArquivo();

        // System.out.println("Select sort normal -----------------");
        // int[] numeros = lerArquivo.lerArquivo("data/numerosOrdenados.txt");
        // selectSort(numeros);


        // System.out.println("Select sort invertido ---------------");
        // int[] numerosInvertidos = lerArquivo.lerArquivo("data/numerosOrdenadosInvertidos.txt");
        // selectSort(numerosInvertidos);

       
         System.out.println("Select Sort Aleatorio");
         int[] numerosAleatorios = lerArquivo.lerArquivo("data/numerosAleatorios.txt");
         selectSort(numerosAleatorios);

    System.out.println("O metodo executou em " + (System.currentTimeMillis() - tempoInicial) +" Milissegundos");
    }
}
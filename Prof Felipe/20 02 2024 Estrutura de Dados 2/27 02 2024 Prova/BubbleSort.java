
public class BubbleSort {
    public static void bubbleSort(int[] numeros) {

        int tamanho = numeros.length;
        int trocas = 0;
        long comparacoes = 0;

        for (int i = 0; i < tamanho; i++) {
            
            for (int j = i+1; j < tamanho; j++) {
                comparacoes++;
                if (numeros[j] < numeros[i]) {
                    int temp = numeros[j];
                    numeros[j] = numeros[i];
                    numeros[i] = temp;
                  
                    trocas++;
                }
            }
        }

        System.out.println("Trocas: " + trocas);
        System.out.println("Comparações: " + comparacoes);
    }
    

    public static void main(String[] args) {
        long tempoInicial = System.currentTimeMillis();
        LerArquivo lerArquivo = new LerArquivo();

        System.out.println("------ Ordenando Numeros -------\n");
        System.out.println("---- BubbleSort -----");
        int[] numeros = lerArquivo.lerArquivo("data/numerosOrdenados.txt");
        bubbleSort(numeros);
              
        // System.out.println("---- BubbleSort Inervitdo -----");
        // int[] numerosInvertidos = lerArquivo.lerArquivo("data/numerosOrdenadosInvertidos.txt");
        // bubbleSort(numerosInvertidos);

        //  System.out.println("---- BubbleSort Aleatorio -----");
        //  int[] numerosAleatorios = lerArquivo.lerArquivo("data/numerosAleatorios.txt");
        //  bubbleSort(numerosAleatorios);
        
        System.out.println("O metodo executou em " + (System.currentTimeMillis() - tempoInicial) +" Milissegundos");
    }
}

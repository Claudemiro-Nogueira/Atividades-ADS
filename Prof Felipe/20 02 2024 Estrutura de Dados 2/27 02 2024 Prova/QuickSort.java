public class QuickSort {
    private static int comparacoes = 0;
    private static int trocas = 0;

    public static void resetContadores() {
        comparacoes =  0;
        trocas =  0;
    }
    public static void troca(int numeros[], int i, int j) {
        int aux;
        aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;  
    }
    public static int particiona(int numeros[], int inicio, int fim) {
        int pivo, i, j;
        pivo = (int) (numeros[(inicio + fim) / 2]);
        i = inicio - 1;
        j = fim + 1;
        while (i < j) {
            comparacoes++;
            do {
                j--;
            } while (numeros[j] > pivo);
            do {
                i++;
            } while (numeros[i] < pivo);
            if (i < j) {
                troca(numeros, i, j);
                trocas++;
            }
        }
        return j;
    }
    public static void quickSort(int numeros[], int inicio, int fim) {
        int pivo;
        if (inicio < fim) {
            pivo = particiona(numeros, inicio, fim);
            quickSort(numeros, inicio, pivo);
            quickSort(numeros, pivo + 1, fim);
        }

    }

    public static void main(String[] args) {
        
        long tempoInicial = System.currentTimeMillis();

        LerArquivo lerArquivo = new LerArquivo();

        System.out.println("Quick Sort Ordenado------");
        int[] numeros = lerArquivo.lerArquivo("data/numerosOrdenados.txt");
        int tamanhoVetor = numeros.length - 1;
        quickSort(numeros, 0, tamanhoVetor);
        System.out.println("Trocas: " + trocas);
        System.out.println("Comparações: " + comparacoes);


        // System.out.println("Quick Sort Inverso --------------");
        // numeros = lerArquivo.lerArquivo("data/numerosOrdenadosInvertidos.txt");
        // tamanhoVetor = numeros.length - 1;
        // resetContadores();
        // quickSort(numeros, 0, tamanhoVetor);
        // System.out.println("Trocas: " + trocas);
        // System.out.println("Comparações: " + comparacoes);

        // System.out.println("Quick Sort Aleatorio --------------");
        // numeros = lerArquivo.lerArquivo("data/numerosAleatorios.txt");
        // tamanhoVetor = numeros.length - 1;
        // resetContadores();
        // quickSort(numeros, 0, tamanhoVetor);

        // System.out.println("Trocas: " + trocas);
        // System.out.println("Comparações: " + comparacoes);
        System.out.println("O metodo executou em " + (System.currentTimeMillis() - tempoInicial) +" Milissegundos");
    }

}
public class InsertSort{

    public static void insertSort(int[] numeros) {
        int j;
        int chave;
        long Troca = 0, comparacoes = 0;
        for (int i = 1; i < numeros.length; i++) {
            
            chave = numeros[i];
            j = i - 1;
            
            while (j >= 0 && numeros[j] > chave) {
                comparacoes++;
                numeros[j + 1] = numeros[j];
                j = j - 1;
            }
            
            numeros[j + 1] = chave;
            Troca++;
        }
        System.out.println("Trocas: " + Troca);
        System.out.println("Comparações: " + comparacoes);
    }
    

    


public static void main(String[] args) {
    long tempoInicial = System.currentTimeMillis();
    LerArquivo lerArquivo = new LerArquivo();

    System.out.println("Insert Sort ----------");
    int[] numeros = lerArquivo.lerArquivo("data/numerosOrdenados.txt");
    insertSort(numeros);

    // System.out.println("Insert Sort Invertido----------");
    // int[] numeros1 = lerArquivo.lerArquivo("data/numerosOrdenadosInvertidos.txt");
    // insertSort(numeros1);

    // System.out.println("Insert Sort Aleatorio----------");
    // int[] numeros2 = lerArquivo.lerArquivo("data/numerosAleatorios.txt");
    // insertSort(numeros2);

System.out.println("O metodo executou em " + (System.currentTimeMillis() - tempoInicial) +" Milissegundos");
}

}
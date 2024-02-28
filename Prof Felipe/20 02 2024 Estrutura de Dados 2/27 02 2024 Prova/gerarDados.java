import java.io.BufferedWriter; // Usa o Buffer interno para escrever no arquivo
import java.io.File;
import java.io.FileWriter; // Usa o FileWriter para escrever diretamente no arquivo
import java.io.IOException; // Tratamento de exceções como erro de escrita

// Garante a não repetição dos numeros
import java.util.HashSet; 
import java.util.Set;


public class gerarDados {
    private int quantidadeNumeros;
   
    private int[] numeros;
    private int comecaEmQualNumero = 0;

    public gerarDados(int quantidadeNumeros) {
        this.quantidadeNumeros = quantidadeNumeros;
        this.numeros = new int[quantidadeNumeros];
    }

    private void gerarNumerosOrdenados() {
        for (int i = comecaEmQualNumero; i < quantidadeNumeros; i++) {
            numeros[i] = i;
        }
    }

    private void gerarNumerosOrdenadosInvertidos() {
        for (int i = comecaEmQualNumero; i < quantidadeNumeros; i++) {
            numeros[i] = quantidadeNumeros - i;
        }
    }

    private void gerarNumerosAleatorios() {
        Set<Integer> numerosGerados = new HashSet<>();
        for (int i = comecaEmQualNumero; i < quantidadeNumeros; i++) {
            int numero;
            do {
                numero = (int) (Math.random() * quantidadeNumeros);
            } while (numerosGerados.contains(numero));
            numerosGerados.add(numero);
            numeros[i] = numero;
        }
    }

    private void escreverNumerosArquivo(String nomeArquivo) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo))) {
            for (int i = comecaEmQualNumero; i < quantidadeNumeros; i++) {
                writer.write(Integer.toString(numeros[i]));
                writer.newLine();
            }
            System.out.println("Números escritos no arquivo '" + nomeArquivo + "' com sucesso.");
        } catch (IOException e) {
            System.out.println("Ocorreu um erro ao escrever no arquivo: " + e.getMessage());
        }
    }

    private void CreateFolder(String folderName) {
        File dataFolder = new File(folderName);
        if (!dataFolder.exists()) {
            boolean created = dataFolder.mkdirs();
            if (!created) {
                System.out.println("Falha ao criar a pasta 'data'.");
                return;
            }
        }
    }

    public static void main(String[] args) {
        int quantidadeNumerosRequeridos = 1000000;

        gerarDados gerador = new gerarDados(quantidadeNumerosRequeridos);

        gerador.CreateFolder("data");

        gerador.gerarNumerosOrdenados();
        gerador.escreverNumerosArquivo("data/numerosOrdenados.txt");
        gerador.gerarNumerosOrdenadosInvertidos();
        gerador.escreverNumerosArquivo("data/numerosOrdenadosInvertidos.txt");
        gerador.gerarNumerosAleatorios();
        gerador.escreverNumerosArquivo("data/numerosAleatorios.txt");
    }
}

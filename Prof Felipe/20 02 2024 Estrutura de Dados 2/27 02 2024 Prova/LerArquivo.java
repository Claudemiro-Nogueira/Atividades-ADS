import java.io.BufferedReader; // Buffer para escrever no arquivo
import java.io.FileReader; // Escrever diretamente no arquivo
import java.io.IOException; // Try / Except

// Criando classe LerArquivo
public class LerArquivo {
    // Contrutor
    public int[] lerArquivo(String nomeArquivo) {
        int[] numeros = new int[1000000];

        try (BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo))) {
            String linha;
            int i = 0;
            while ((linha = reader.readLine()) != null && i < 1000000) {
                numeros[i] = Integer.parseInt(linha);
                i++;
            }
        } catch (IOException e) {
            System.out.println("Erro" + e.getMessage());
        }
        return numeros;
    }
}
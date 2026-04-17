package università.programmazione.esercizi_java.src.esercizio_cerchio;

import java.util.Scanner;

public class Test_Cerchio {

    public static void main(String[] args){

        int dim = 5;
        int riemp = 0;
        int cont = 1;

        Cerchio array [] = new Cerchio[dim];

        Scanner scanner = new Scanner(System.in);

        for(int i = 0; i < dim; i++){

            riemp ++;
            System.out.printf("Inserisci il raggio del cerchio " + riemp + ": \n");
            double r = scanner.nextDouble();
            array[i] = new Cerchio(r);

            System.out.printf("Riempimento attuale: " + riemp + "\n");

        }

        for(Cerchio elem: array){

            System.out.printf("Perimetro del cerchio " + cont + ": \n" + elem.perimetro(elem.get_raggio()) + "\n");
            cont ++;
        }

        scanner.close();

    }
    
}

package università.programmazione.esercizio_contatore;

public class EsercizioContatore {
    
        public static void main(String[] args){

            Counter b = new Counter();
            Counter c = new Counter(4);
            Counter d = new Counter(c);

            System.out.print("Valore corrente del contatore b: " + b.get_value() + "\n");
            System.out.print("Valore corrente del contatore c: " + c.get_value() + "\n");
            System.out.print("Valore corrente del contatore d: " + d.get_value() + "\n");

            System.out.print("Valore soglia del contatore b: " + b.get_max() + "\n");
            System.out.print("Valore soglia del contatore c: " + c.get_max() + "\n");
            System.out.print("Valore soglia del contatore d: " + d.get_max() + "\n");

            if(!c.ovf()){
                c.increment();
                System.out.print("Valore del contatore c dopo l'incremento: " + c.get_value() + "\n");
            }
            else System.out.print("pre-condizione non verificata, impossibile incrementare c!" + "\n");
            
            if(!c.unf()){
                c.decrement();
                System.out.print("Valore del contatore c dopo il decremento: " + c.get_value() +"\n");
            }
            else System.out.print("Pre-condizione non verificata, impossibile decrementare c!" + "\n");

            d.set_max(20);
            System.out.print("Valore soglia del conto d: " + d.get_max() + "\n");
        }
}

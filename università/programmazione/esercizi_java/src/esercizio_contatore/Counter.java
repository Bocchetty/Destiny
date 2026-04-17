package università.programmazione.esercizi_java.src.esercizio_contatore;

public class Counter {

        private long value;
        private long max;

        //Overloading di costruttori: il compilatore in base agli argomenti dati nella creazione delle nuove istanze nel main sceglie il costruttore piùa datto

        //costruttore senza argomenti (usato per il counter b)
        public Counter() {
            max = 12; 
            value = 0;
        }

        //costruttore con argomenti (usato per il counter c)
        public Counter(long m) {max = m; value = 0;}

        //costuttore di copia (usato per il counter d)
        public Counter(Counter c) {
            max = c.max; 
            value = c.value;
        }

        //getter
        public long get_value() {return value;}
        public long get_max() {return max;}

        //setter
        public void set_max(long m) {max=m;}

        //metodi per la gestione del contatore
        public void decrement() {value--;}
        public void increment() {value++;}

        //predicati
        public boolean ovf() {return (value+1) >= max;}
        public boolean unf() {return (value-1) < 0;}
}

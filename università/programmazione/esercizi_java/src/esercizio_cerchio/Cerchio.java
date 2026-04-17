package università.programmazione.esercizi_java.src.esercizio_cerchio;

public class Cerchio {

    // Coordinate cerchio
    private double x;
    private double y;
    // Raggio cerchio
    private double raggio;

    // Costruttore con argomenti che imposta il centro all'origine degli assi
    public Cerchio(double r){
        x = 0;
        y = 0;
        raggio = r;
    }

    // Metodi get
    public double get_x(){
        return x;
    }

    public double get_y(){
        return y;
    }

    public double get_raggio(){
        return raggio;
    }

    // Metodi set
    public void set_x(double c_x){
        x = c_x;
    }

    public void set_y(double c_y){
        y = c_y;
    }

    public void set_raggio(double r){
        raggio = r;
    }
    
    public double area(double raggio){
        return Math.PI * Math.pow(raggio, 2);
    }

    public double perimetro(double raggio){
        return 2 * Math.PI * raggio;
    }
}

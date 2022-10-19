public class TekRacunaA {
    
    private String broj;
    private String vlasnik;
    private double stanje;

    public TekRacunaA() {
        broj = "";
        vlasnik = "";
        stanje = 0.0;
    }

    public TekRacunaA(String b, String vl, double st) {
        this.broj = b;
        this.vlasnik = vl;
        this.stanje = st;
    }

    public String getBroj() { 
        return this.broj;
    }

    public String getVlasnik() {
        return this.vlasnik;
    }

    public double getStanje() {
        return this.stanje;
    }

    public void setBroj(String st) {
        this.broj = st;
    }

    public void setVlasnik(String vl) {
        this.vlasnik = vl;
    }

    public void setStanje(double st) {
        this.stanje = st;
    } 

    @Override
    public boolean equals(Object tekRacuna) {
        if(!(tekRacuna instanceof TekRacunaA)) return false;

        TekRacunaA t = (TekRacunaA) tekRacuna;

        if(!(this.broj.equals(t.broj))) return false;
        if(!(this.vlasnik.equals(t.vlasnik))) return false;
        if(!(this.stanje == t.stanje)) return false;
        
        return true;
    }

    public void uplata(double pare) {
        this.stanje += pare;
    }

    public void isplata(double pare) {
        if(this.stanje - pare >= 0)
            this.stanje -= pare;
        else 
            System.out.println("Nema dovoljno para.");
    }

    @Override
    public String toString() {
        return "[" + this.getVlasnik() + " - " + this.getStanje() + " - " + this.getBroj() + "]";
    }

}

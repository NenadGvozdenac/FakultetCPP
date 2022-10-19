public class TekRacunaB extends TekRacunaA {

    private double dozvoljeniMinus;

    public TekRacunaB() {
        this.dozvoljeniMinus = 0;
        this.setStanje(0);
        this.setVlasnik("");
        this.setBroj("");
    }

    public TekRacunaB(String vlasnik, String broj, double stanje, double minus) {
        this.setStanje(stanje);
        this.setBroj(broj);
        this.setVlasnik(vlasnik);
        this.setDozMinus(minus);
    }

    public double getDozMinus() {
        return dozvoljeniMinus;
    }

    public void setDozMinus(double minus) {
        this.dozvoljeniMinus = minus;
    }

    @Override
    public void isplata(double pare) {
        if(pare - dozvoljeniMinus >= 0) {
            this.setStanje(pare - dozvoljeniMinus);
        }
    }

    @Override
    public String toString() {
        return "[" + this.getVlasnik() + " - " + this.getStanje() + " - " + this.getBroj() + " - " + this.getDozMinus() + "]";
    }
}

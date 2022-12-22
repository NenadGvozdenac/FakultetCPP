public abstract class Test {
    private String naziv;
    private int osvojeniPoeni;

    public Test() {
        naziv = "";
        osvojeniPoeni = 0;
    }

    public Test(String naziv, int osvojeniPoeni) {
        this.naziv = naziv;
        this.osvojeniPoeni = osvojeniPoeni;
    }

    public int getOsvojeniPoeni() {
        return osvojeniPoeni;
    }

    public String getNaziv() {
        return this.naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public void setOsvojeniPoeni(int osvojeniPoeni) {
        this.osvojeniPoeni = osvojeniPoeni;
    }

    abstract boolean polozio();
}

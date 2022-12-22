public class Kolokvijum extends Test {
    public Kolokvijum() {
        super();
    }

    public Kolokvijum(String naziv, int osvojeniPoeni) {
        super(naziv, osvojeniPoeni);
    }

    public boolean polozio() {
        return (super.getOsvojeniPoeni() > 12) ? true : false;
    }

    @Override
    public String toString() {
        String str = String.format("----------- KOLOKVIJUM --------------\nNaziv: %s\nOsvojeni poena: %s\n-------------------------------------\n", super.getNaziv(), super.getOsvojeniPoeni());
        return str;
    }
}

import java.util.ArrayList;

public class Predmet implements IPredmet {
    private String naziv;
    private ArrayList<Test> predmeti;

    public Predmet() {
        this.naziv = "";
        this.predmeti = new ArrayList<>();
    }

    public Predmet(String naziv, ArrayList<Test> predmeti) {
        this.naziv = naziv;
        this.predmeti = predmeti;
    }

    public String getNaziv() {
        return this.naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public boolean polozio() {
        for(Test test : predmeti) {
            if(!test.polozio() || test.getOsvojeniPoeni() <= 55) {
                return false;
            }
        }

        return true;
    }

    public int izracunajPoene() {
        int brojOsvojenihPoena = 0;
       
        for(Test test : predmeti) {
            brojOsvojenihPoena += test.getOsvojeniPoeni();
        }

        return brojOsvojenihPoena;
    }

    public boolean dodajTest(Test t) {
        for(Test test : predmeti) {
            if(t.getNaziv().equals(test.getNaziv())) {
                return false;
            }
        }

        return predmeti.add(t);
    }

    @Override
    public String toString() {
        String str = String.format("************* Predmet ***************\nNaziv: %s\nTestovi:\n", this.naziv);
        if(predmeti.isEmpty()) {
            str += "Lista testova je prazna";
        } else {
            for(Test test : predmeti) {
                str += test + "\n";
            }
        }
        
        str += "*************************************";
        
        return str;
    }
}
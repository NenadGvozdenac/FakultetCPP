import java.util.HashMap;
import java.util.Map;

public class Student {
    private String prezime;
    private String indeks;  // ra133/2021
    private HashMap<String, Predmet> predmeti;

    public Student() {
        this.prezime = this.indeks = "";
        this.predmeti = new HashMap<>();
    }

    public Student(String prezime, String indeks, HashMap<String, Predmet> predmeti) {
        this.prezime = prezime;
        this.indeks = indeks;
        this.predmeti = predmeti;
    }

    public boolean dodajPredmet(Predmet p) {
        if(predmeti.size() > 10) {
            return false;
        }

        for(Map.Entry<String, Predmet> entry : predmeti.entrySet()) {
            if(entry.getKey().equals(p.getNaziv())) {
                return false;
            }
        }

        predmeti.put(p.getNaziv(), p);
        return true;
    }

    public boolean polozioGodinu() {
        for(Predmet p : predmeti.values()) {
            if(!p.polozio()) {
                return false;
            }
        }

        predmeti.clear();
        return true;
    }

    public String formirajEMailAdresu() {
        String email = "";
        email += indeks.substring(0, 2);
        email += ".";
        email += prezime;

        String[] temp = indeks.split("/");
        email += temp[0].substring(2, temp[0].length());
        email += "-";
        email += temp[1];
        email += "@uns.ac.rs";

        return email;
    }

    public int trajanjeStudija() {
        String[] temp = indeks.split("/");
        try {
            Integer i = Integer.parseInt(temp[1]);
            return 2022 - i;
        } catch(NumberFormatException e) {
            System.out.println("Desio se izuzteka prilikom pokusaja parsiranja!");
            System.out.println(e.getMessage());
            return 0;
        }
    }

    @Override
    public String toString() {
        return "[Student: Prezime -> " + prezime + ", Indeks -> " + indeks + ", Email -> " + this.formirajEMailAdresu() + ", Godina studiranja -> " + this.trajanjeStudija() + "]";
    }
}

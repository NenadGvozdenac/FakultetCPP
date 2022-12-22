import java.util.ArrayList;
import java.util.HashMap;

public class App {
    public static void main(String[] args) throws Exception {
        Kolokvijum k1 = new Kolokvijum();
        Kolokvijum k2 = new Kolokvijum("Prvi Kolokvijum", 60);
        Kolokvijum k3 = new Kolokvijum("Drugi Kolokvijum", 80);
        Kolokvijum k4 = new Kolokvijum("Prvi Kolokvijum", 15);
        Kolokvijum k5 = new Kolokvijum("Drugi Kolokvijum", 100);
        
        System.out.println("Polozio prvi kolokvijum: " + k2.polozio());
        System.out.println(k1);

        ArrayList<Test> listaKolokvijumaAnaliza = new ArrayList<>() {
            {
                add(k2);
                add(k3);
            }
        };

        ArrayList<Test> listaKolokvijumaObjektno = new ArrayList<>() {
            {
                add(k4);
                add(k5);
            }
        };

        Predmet p1 = new Predmet();
        Predmet p2 = new Predmet("Analiza 1", listaKolokvijumaAnaliza);
        Predmet p3 = new Predmet("Objektno", listaKolokvijumaObjektno);

        System.out.println(p1.getNaziv());
        System.out.println(p1.polozio());

        System.out.println("Ukupno poena na analizi 1: " + p2.izracunajPoene());

        Kolokvijum k6 = new Kolokvijum("Usmeni", 30);
        p2.dodajTest(k6);

        System.out.println(p2);

        HashMap<String, Predmet> listaPredmeta = new HashMap<>() {
            {
                put(p2.getNaziv(), p2);
                put(p3.getNaziv(), p3);
            }
        };

        Student student = new Student();
        Student student2 = new Student("Retardirani", "RA1/2021", listaPredmeta);

        student2.dodajPredmet(p1);
        System.out.println("Polozio godinu: " + student2.polozioGodinu());
        System.out.println(student2);

    }
}

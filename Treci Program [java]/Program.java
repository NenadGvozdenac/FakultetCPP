import java.util.ArrayList;

public class Program {
    public static void main(String[] args) {

        ArrayList<TekRacunaB> lista = new ArrayList<TekRacunaB>();

        lista.add(new TekRacunaB("Nenad", "1", 200000, 0));
        lista.add(new TekRacunaB("Nenad2", "2", 200000, 0));
        lista.add(new TekRacunaB("Nenad3", "4", 50000, 0));
        lista.add(new TekRacunaB("Nenad4", "3", 6200000, 0));
        lista.add(new TekRacunaB("Nenad5", "5", 15, 0));
        lista.add(new TekRacunaB("Nenad6", "6", 0, 0));

        Evidencija evidencija = new Evidencija("12.02.2003", lista);
        evidencija.sortirajPoStanju();
        System.out.println(evidencija);

    }
}
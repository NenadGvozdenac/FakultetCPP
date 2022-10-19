import java.util.ArrayList;

public class Evidencija {
    private String datum;
    private ArrayList<TekRacunaB> listaRacuna;

    public Evidencija() {
        datum = "";
        listaRacuna = new ArrayList<>();
    }

    public Evidencija(String datum, ArrayList<TekRacunaB> lista) {
        this.datum = datum;
        this.listaRacuna = lista;
    }

    public void addToListaRacuna(TekRacunaB e) {
        listaRacuna.add(e);
    }

    public void removeFromListaRacuna(TekRacunaB e) {
        listaRacuna.remove(e);
    }

    public TekRacunaB getNaOsnovuBroja(String broj) {
        for(TekRacunaB t : listaRacuna) {
            if(t.getBroj().equals(broj)) {
                return t;
            }
        }

        return null;
    }

    @Override
    public String toString() {
        return "[" + datum + " - " + listaRacuna + "]";
    }

    public void sortirajPoStanju() {
        for(int i = 0; i < listaRacuna.size() - 1; i++) {
            for(int j = 0; j < listaRacuna.size() - 1 - i; j++) {
                if(listaRacuna.get(i+1).getStanje() < listaRacuna.get(i).getStanje()) {
                    TekRacunaB temp = listaRacuna.get(i);
                    listaRacuna.set(i, listaRacuna.get(i+1));
                    listaRacuna.set(i+1, temp);
                }
            }
        }
    }
}

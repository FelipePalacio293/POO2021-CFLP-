using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class Entidad
{
    [SerializeField] int nivel;
    [SerializeField] EntidadBase entidadBase;

    public int getNivel {
        get { return nivel; }
    }

    public EntidadBase getEntidadBase
    {
        get { return entidadBase; }
    }

    public int Vida{get; set;}

    public List<Poder> Poderes {get; set;}

    public void iniciarBatalla()
    {
        Vida = PuntosDeVidaMax;

        Poderes = new List<Poder>();
        foreach(var poder in getEntidadBase.PoderAprendibles)
        {
            if(poder.Nivel <= getNivel)
            {
                Poderes.Add(new Poder(poder.pBase));
            }

            if(Poderes.Count >= 2)
                break;
        }
    }

    public int Atacar
    {
        get{return Mathf.FloorToInt((getEntidadBase.PuntosDeDanio * getNivel) / 100f);}
    }

    public int PuntosDeVidaMax
    {
        get{return Mathf.FloorToInt(getEntidadBase.PuntosDeVidaMax * getNivel);}
    }

    public bool recibirDano(Poder poder, Entidad atacador)
    {
        int danio = Mathf.FloorToInt((poder.Base.PoderDeAtaque * getNivel) - getEntidadBase.getPuntosDefensa() * 0.2f);
        Vida -= danio;
        if(Vida <= 0)
        {
            Vida = 0;
            return true;
        }

        return false;

    }

    public void mostrarPoderes()
    {
        foreach (Poder pod in Poderes)
        {
            Debug.Log(pod.Base.Nombre);
        }
    }

    public Poder getRandomPoder()
    {
        int r = Random.Range(0, 2);
        return Poderes[0];
    }
}

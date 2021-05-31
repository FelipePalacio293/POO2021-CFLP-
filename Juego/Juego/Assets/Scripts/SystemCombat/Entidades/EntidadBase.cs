using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Entidad", menuName = "Entidad/Crear una nueva entidad")]
public class EntidadBase : ScriptableObject
{
    [SerializeField] string nombre;
    [SerializeField] int puntosDeDanio;
    [SerializeField] int puntosDeVidaMax;
    [SerializeField] int puntosDefensa;
    [SerializeField] Sprite sprite;   
    [SerializeField] List<PoderAprendible> poderAprendibles; 

    public void setPuntosDanio(int danio)
    {
        puntosDeDanio += danio;
    }

    public int getPuntosDanio()
    {
        return puntosDeDanio;
    }

    public string Nombre
    {
        get{return nombre;}
    }

    public int getPuntosDefensa()
    {
        return puntosDefensa;
    }

    public void setPuntosDefensa(int defensa)
    {
        if(defensa + puntosDefensa < 10)
        {
            puntosDefensa += defensa;
        }
    }

    public int PuntosDeDanio { get; set; }

    public int PuntosDeVidaMax
    {
        get{return puntosDeVidaMax;}
    }

    public List<PoderAprendible> PoderAprendibles
    {
        get {return poderAprendibles;}
    }

    public Sprite Sprite
    {
        get{return sprite;}
    }
}

[System.Serializable]
public class PoderAprendible
{
    [SerializeField] PoderBase poderBase;
    [SerializeField] int nivel;
    public int Nivel
    {
        get{return nivel;}
    }
    public PoderBase pBase
    {
        get{return poderBase;}
    }
}

public enum EntidadType
{
    None = 1,
    Caballero,
    Minotauro,
    Dragon,
    Ciclope
}

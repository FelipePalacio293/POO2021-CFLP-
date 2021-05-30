using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Entidad", menuName = "Entidad/Crear una nueva entidad")]
public class EntidadBase : ScriptableObject
{
    [SerializeField] string nombre;
    [SerializeField] int puntosDeDanio;
    [SerializeField] int puntosDeVidaMax;
    [SerializeField] Sprite sprite;   
    [SerializeField] List<PoderAprendible> poderAprendibles; 


    public string Nombre
    {
        get{return nombre;}
    }

    public int PuntosDeDanio{
        get{return puntosDeDanio;}
    }
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

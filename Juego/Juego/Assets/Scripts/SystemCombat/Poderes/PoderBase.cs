using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Poder", menuName = "Poder/Crear nuevo poder")]
public class PoderBase : ScriptableObject
{
    [SerializeField] string nombre;
    [SerializeField] int poderDeAtaque;

    public string Nombre
    {
        get{return nombre;}
    }

    public int PoderDeAtaque
    {
        get{return poderDeAtaque;}
    }
    
}

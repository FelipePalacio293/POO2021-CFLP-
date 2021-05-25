using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Entidad : MonoBehaviour
{
    protected string nombre;
    protected int puntosDeVida = 0;
    protected int puntosDeDanio;
    
    public abstract void morir(); 
}

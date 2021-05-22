using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class Entidad : MonoBehaviour
{
    protected int puntosDeVida = 0;
    private int puntosDeDanio;

    public abstract void morir(); 
}

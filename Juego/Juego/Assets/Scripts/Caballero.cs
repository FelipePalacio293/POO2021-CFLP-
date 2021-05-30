using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Caballero : MonoBehaviour
{
    [SerializeField] Entidad entidadCaballero;

    private void Start()
    {
        entidadCaballero.iniciarBatalla();
    }

    public Entidad getEntidad()
    {
        return entidadCaballero;
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PocionVida : Item
{
    [SerializeField] private int vidaACurar;
    public int darVidaAlJugador()
    {
        return vidaACurar;
    }
}

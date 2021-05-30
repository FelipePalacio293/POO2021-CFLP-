using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Poder 
{
    public PoderBase Base {get; set;}
    public Poder(PoderBase pBase)
    {
        Base = pBase;
    }
}

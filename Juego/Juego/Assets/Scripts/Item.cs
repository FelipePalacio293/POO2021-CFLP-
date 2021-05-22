using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item
{
    public enum ItemType
    {
        espada,
        arco,
        baculo,
        lanza,
        pocionVida,
        pocionDanio,
        pocionAumentoDanio,
        pocionHuida
    }

    public ItemType itemType;
}

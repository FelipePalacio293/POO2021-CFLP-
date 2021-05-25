using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class Item
{
    public enum ItemType
    {
        espada,
        hacha,
        lanza,
        pocionVida,
        pocionDanio,
        pocionAumentoDanio,
        pocionHuida,
        llave
    }

    public ItemType itemType;
    public int cantidadItem;
    public bool esStackeable;

    public bool getEsStackeable()
    {
        return this.esStackeable;
    }

    public Sprite getSprite()
    {
        switch (itemType)
        {
            default:
            case ItemType.espada:               return ItemAssets.Instance.spriteEspada;
            case ItemType.lanza:                return ItemAssets.Instance.spriteLanza;
            case ItemType.hacha:                return ItemAssets.Instance.spriteHacha;
            case ItemType.pocionVida:           return ItemAssets.Instance.spritePocionVida;
            case ItemType.pocionDanio:          return ItemAssets.Instance.spritePocionDanio;
            case ItemType.pocionAumentoDanio:   return ItemAssets.Instance.spritePocionHuir;
            case ItemType.pocionHuida:          return ItemAssets.Instance.spritePocionHuir;
            case ItemType.llave:                return ItemAssets.Instance.spriteLlave;
        }
    }

    public bool comprobarSiEsStackeable()
    {
        switch (itemType)
        {
            default:
            case ItemType.pocionAumentoDanio:
            case ItemType.pocionDanio:
            case ItemType.pocionVida:
            case ItemType.pocionHuida:
                return true;
            case ItemType.espada:
            case ItemType.hacha:
            case ItemType.lanza:
                return false;
        }
    }
}

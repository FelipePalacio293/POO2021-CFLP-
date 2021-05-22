using System.Collections;
using System.Collections.Generic;
using UnityEngine;

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
        pocionHuida
    }

    public ItemType itemType;
    public int cantidadItem;

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

        }
    }
}

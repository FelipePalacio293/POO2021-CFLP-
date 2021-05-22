using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Inventario
{
    List<Item> items;
    private int capacidadInventario = 10;
    public Inventario()
    {
        items = new List<Item>();
        agregarItem(new Item { itemType = Item.ItemType.espada });
        agregarItem(new Item { itemType = Item.ItemType.pocionVida });
        agregarItem(new Item { itemType = Item.ItemType.pocionDanio });
    }

    public void agregarItem(Item item)
    {
        items.Add(item);
    }

    public List<Item> getItemList()
    {
        return items;
    }
}

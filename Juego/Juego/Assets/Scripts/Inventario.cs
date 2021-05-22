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
        agregarItem(new Item { itemType = Item.ItemType.espada, cantidadItem = 1 });
        agregarItem(new Item { itemType = Item.ItemType.hacha, cantidadItem = 1 });
        agregarItem(new Item { itemType = Item.ItemType.lanza, cantidadItem = 1 });
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

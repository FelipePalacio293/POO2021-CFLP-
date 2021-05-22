using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InventoryUI : MonoBehaviour
{
    private Inventario inventario;
    private Transform itemSlotContainer;
    private Transform itemSlotTemplate;

    private void Awake()
    {
        itemSlotContainer = transform.Find("itemSlotContainer");
        itemSlotTemplate = itemSlotContainer.Find("itemSlotTemplate");
    }

    public void setInventario(Inventario inventario)
    {
        this.inventario = inventario;
        refrescarItemsInventario();
    }

    public void refrescarItemsInventario()
    {
        int x = 0;
        int y = 0;
        float itemSlotSize = 100f;
        foreach(Item item in inventario.getItemList())
        {
            RectTransform itemSlotRectTransform = Instantiate(itemSlotTemplate, itemSlotContainer).GetComponent<RectTransform>();
            itemSlotRectTransform.gameObject.SetActive(true);
            itemSlotRectTransform.anchoredPosition = new Vector2(x * itemSlotSize, y * itemSlotSize);
            x++;
            if(x > 4)
            {
                x = 0;
                y++;
            }
        }
    }
}

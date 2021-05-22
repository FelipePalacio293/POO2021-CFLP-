using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class InventoryUI : MonoBehaviour
{
    private Inventario inventario;
    private Transform itemSlotContainer;
    private Transform itemSlotTemplate;

    private void Awake()
    {
       
    }

    public void setInventario(Inventario inventario)
    {
        itemSlotContainer = transform.Find("itemSlotContainer");
        itemSlotTemplate = itemSlotContainer.Find("itemSlotTemplate");
        this.inventario = inventario;
        refrescarItemsInventario();
    }

    public void refrescarItemsInventario()
    {
        int x = 0;
        int y = 0;
        float itemSlotSize = 60f;
        foreach(Item item in inventario.getItemList())
        {
            RectTransform itemSlotRectTransform = Instantiate(itemSlotTemplate, itemSlotContainer).GetComponent<RectTransform>();
            itemSlotRectTransform.gameObject.SetActive(true);
            itemSlotRectTransform.anchoredPosition = new Vector2(x * itemSlotSize, y * itemSlotSize);
            Image image = itemSlotRectTransform.Find("image").GetComponent<Image>();
            image.sprite = item.getSprite();
            x++;
            if(x > 4)
            {
                x = 0;
                y++;
            }
        }
    }
}

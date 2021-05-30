using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    private float speed = 3f;
    private Animator anim;
    private Rigidbody2D rigidbody2D;
    private Vector2 mov;
    private Inventario inventario;
    private bool inventarioAbierto;
    private bool peleaActiva;

    public event Action iniciadorPeleas;

    [SerializeField] private InventoryUI inventarioUI;
    [SerializeField] private GameObject canvasInventario;
    private GameObject enemigoAtacandoActual;

    private void Awake()
    {

    }

    void Start()
    {
        inventario = new Inventario();
        canvasInventario.SetActive(false);
        inventarioUI.setInventario(inventario);
        peleaActiva = false;
        inventarioAbierto = false;
        anim = GetComponent<Animator>();
        rigidbody2D = GetComponent<Rigidbody2D>();
    }

    public void habilitarUpdate()
    {
        if (!peleaActiva)
        {
            if (!inventarioAbierto)
            {
                caminar();
            }
            if (inventarioAbierto)
            {
                cerrarInventario();
            }
            else
            {
                abrirInventario();
            }
        }
    }

    void FixedUpdate()
    {
        actualizarPosicion();
    }

    void caminar()
    {
        mov = new Vector2(
            Input.GetAxisRaw("Horizontal"),
            Input.GetAxisRaw("Vertical")
        );

        if (mov != Vector2.zero)
        {
            anim.SetFloat("movX", mov.x);
            anim.SetFloat("movY", mov.y);
            anim.SetBool("caminar", true);
        }
        else
        {
            anim.SetBool("caminar", false);
        }
    }

    void actualizarPosicion()
    {
        rigidbody2D.MovePosition(rigidbody2D.position + mov * speed * Time.deltaTime);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        ItemMundo itemMundo = collision.GetComponent<ItemMundo>();
        if (itemMundo != null)
        {
            if (inventario.comprobarSiPuedeAgregarItem())
            {
                inventario.agregarItem(itemMundo.getItem());
                itemMundo.destruirItem();
            }
        }
        if (collision.gameObject.CompareTag("Enemigo"))
        {
            mov = Vector2.zero;
            anim.SetBool("caminar", false);
            enemigoAtacandoActual = collision.gameObject;
            iniciadorPeleas();
            Destroy(collision.gameObject);
        }
    }

    public GameObject getEnemigoActual()
    {
        return enemigoAtacandoActual;
    }

    private void OnTriggerStay2D(Collider2D collision)
    {

    }

    public void abrirInventario()
    {
        if (Input.GetKeyDown(KeyCode.E) && !inventarioAbierto)
        {
            canvasInventario.SetActive(true);
            inventarioAbierto = true;
        }
    }

    public void cerrarInventario()
    {
        if (Input.GetKeyDown(KeyCode.E) && inventarioAbierto)
        {
            canvasInventario.SetActive(false);
            inventarioAbierto = false;
        }
    }

    public void anaidirDelay()
    {

    }
}

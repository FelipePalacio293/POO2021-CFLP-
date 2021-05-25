using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : Entidad
{
    private float speed = 6f;
    private Animator anim;
    private Rigidbody2D rigidbody2D;
    private Vector2 mov;
    private Inventario inventario;
    private bool inventarioAbierto;

    [SerializeField] private GameObject canvasInventario;
    [SerializeField] private InventoryUI inventarioUI;

    private void Awake()
    {
        
    }

    void Start()
    {
        inventarioAbierto = false;
        inventario = new Inventario();
        inventarioUI.setInventario(inventario);
        anim = GetComponent<Animator>();
        rigidbody2D = GetComponent<Rigidbody2D>();
        canvasInventario.SetActive(false);
    }

    void Update()
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

        if(mov != Vector2.zero)
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
        if(itemMundo != null)
        {
            if (inventario.comprobarSiPuedeAgregarItem())
            {
                inventario.agregarItem(itemMundo.getItem());
                itemMundo.destruirItem();
            } 
        }
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

    public override void morir()
    {
        if (this.puntosDeVida <= 0)
        {
            
        }
    }
}

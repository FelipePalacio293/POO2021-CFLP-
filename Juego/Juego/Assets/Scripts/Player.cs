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

    [SerializeField] private InventoryUI inventarioUI;

    private void Awake()
    {
        inventario = new Inventario();
        inventarioUI.setInventario(inventario);
    }

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
        rigidbody2D = GetComponent<Rigidbody2D>();      
    }

    // Update is called once per frame
    void Update()
    {
        caminar();
        morir(); 
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
            anim.SetFloat("MovX", mov.x);
            anim.SetFloat("MovY", mov.y);
        }
    }

    void actualizarPosicion()
    {
        rigidbody2D.MovePosition(rigidbody2D.position + mov * speed * Time.deltaTime);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Recolectable"))
        {
            Destroy(collision.gameObject);
        }
    }

    public override void morir()
    {
        if (this.puntosDeVida <= 0)
        {
            
        }
    }
}

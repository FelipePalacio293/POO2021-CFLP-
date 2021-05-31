using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    private float speed = 4f;
    private Animator anim;
    private Rigidbody2D rigidbody2D;
    private Vector2 mov;

    public event Action iniciadorPeleas;

    private GameObject enemigoAtacandoActual;
    private string animacionActual;

    private void Awake()
    {

    }

    public void setAnimacionActual(string animacionActual)
    {
        this.animacionActual = animacionActual;
    }

    void Start()
    {
        animacionActual = "caminar";
        anim = GetComponent<Animator>();
        rigidbody2D = GetComponent<Rigidbody2D>();
    }

    public void habilitarUpdate()
    { 
        
        caminar();
        
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
            anim.SetBool(animacionActual, true);
        }
        else
        {
            anim.SetBool(animacionActual, false);
        }
    }

    void actualizarPosicion()
    {
        rigidbody2D.MovePosition(rigidbody2D.position + mov * speed * Time.deltaTime);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
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
}